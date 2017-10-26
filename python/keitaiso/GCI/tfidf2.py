#coding: utf-8
from __future__ import division
import MeCab
from math import log10 as log
import sys


global N  # idf の計算で使いたいのでグローバル変数として宣言しておく
try:
    rank = int(sys.argv[1])
except:
    rank = 10
parties = ['jimin', 'minsyu', 'kyousan']
N = len(parties)  # 主要政党の数
sentences = ['' for i in range(N)]  # 文書を入れていくリスト

# 各政党のマニフェストを sentences に読み込む
for i in range(N):
    filename = parties[i] + '.txt'
    f = open(filename, 'r')
    lines = f.readlines()
    for line in lines:
        sentences[i] += line.strip()
    f.close()

# 各文書の分析結果，データの入れ物を用意
taggers = [MeCab.Tagger() for i in range(N)]
results = [taggers[i].parseToNode(sentences[i]) for i in range(N)]
wordCounts = [{} for i in range(N)]
wordSets = [set() for i in range(N)]

# 各文書の名詞を取り出して記録，語数をカウント
for i in range(N):
    while results[i]:
        splited_result = results[i].feature.split(',')
        if splited_result[0] == '名詞' and splited_result[1] != '接尾':
            wordCounts[i].setdefault(results[i].surface, 0)
            wordCounts[i][results[i].surface] += 1
            wordSets[i].add(results[i].surface)
        results[i] = results[i].next


# tf 値を計算
def tf(word, doc):
    n = wordCounts[doc][word]
    nlist = [wordCounts[doc][w] for w in wordSets[doc]]
    return n / sum(nlist)


# idf 値を計算
def idf(word):
    df = 0
    for i in range(N):
        if word in wordSets[i]:
            df += 1
    return log(N / df) + 1

# tf-idf 値の入れ物を用意
tfidfs = [{} for i in range(N)]

# 各単語の tf-idf 値を計算
for i in range(N):
    for word in wordSets[i]:
        tfidfs[i][word] = tf(word, i) * idf(word)

# 単語を tf-idf 値の高い順にソートする
sorted_tfidfs = [[] for i in range(N)]
sorted_words = [[] for i in range(N)]
for i in range(N):
    sorted_tfidfs[i] = sorted(
        tfidfs[i].items(), key=lambda x: x[1], reverse=True
    )
    sorted_words[i] = [x[0] for x in sorted_tfidfs[i]]
    print '%s:' % parties[i], ", ".join(sorted_words[i][:rank])


# 単語のベクトルの類似度を計算
# どれくらいの割合の単語が共通しているか
def similarity(list1, list2):
    count = 0
    for x in list1:
        if x in list2:
            count += 1
    return count / len(list1)

# 結果を表示
for i in range(N):
    print '%s と %s の類似度:' % (parties[i], parties[(i+1) % N])
    print similarity(sorted_words[i][:rank], sorted_words[(i+1) % N][:rank])
