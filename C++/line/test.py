#coding:utf-8
import sys

# 使用に外れる １つ以上の演算子と１つの=が存在しなければ終了コード1
# 文字列を' 'で分割したlist作ったのでinで入ってなければ終了
# 正規表現で[0~9, a~z, A~Z]と演算子' ',=のみ通す


s_input = list(sys.argv[1].split(' '))
print("{0}".format(s_input))


# 入力ルールチェック
operator = ['+', '-', '*', '/']
equal = '='

count_op = 0;
for x in operator:
    if (x in s_input) == 1:
        count_op += 1
if count_op == 0:
    print("演算子エラー")
if ('=' in s_input) == 0:
    print("=なし")


# マッピング（全探索）

