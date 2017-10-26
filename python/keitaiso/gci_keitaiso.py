#coding:utf-8
import MeCab

sentence = '日本国民は、正当に選挙された国会における代表者を通じて行動し、われらとわれらの子孫のために、諸国民との協和による成果と、わが国全土にわたつて自由のもたらす恵沢を確保し、政府の行為によつて再び戦争の惨禍が起ることのないやうにすることを決意し、ここに主権が国民に存することを宣言し、この憲法を確定する。そもそも国政は、国民の厳粛な信託によるものであつて、その権威は国民に由来し、その権力は国民の代表者がこれを行使し、その福利は国民がこれを享受する。これは人類普遍の原理であり、この憲法は、かかる原理に基くものである。われらは、これに反する一切の憲法、法令及び詔勅を排除する。'

tagger = MeCab.Tagger()
result = tagger.parse(sentence)
print(result)

wordCount = {}
wordList = result.split()[:-1:2]
for word in wordList:
   wordCount.setdefault(word,0)
   wordCount[word]+=1

for word,count in wordCount.items():
#   print('%-16s %i') % (word, count)
   print('{0} {1}'.format(word, count))
