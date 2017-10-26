#coding:utf-8

import sys
import re         #regular expression


while True:
    #print "Input imformation of gene>",
    try:
        genes_raw = raw_input()
    except EOFError:
        break

    #pat = re.compile("[A-Za-z][A-Za-z][A-Za-z][0-9]")
    #r = pat.match(n[8:12])

    Chr = re.compile("Chr")
    r = Chr.search(genes_raw)

    #">"の列だけがFASTA配列のヘッダー行
    if genes_raw[0] == ">":

        genes = genes_raw.split(" ")   #genesの語句を分割
        gene_character = {}            #必要な情報だけ辞書に
        gene_character['ORFname'] = genes[0]
        gene_character['GeneName'] = genes[1]
        gene_character['SGDID'] = genes[2]
        gene_character['ChrNum'] = "%s %s" % (genes[3],genes[4])

        r = Chr.search(gene_character['ChrNum'])
        if (r != None) == True:
        #指定の出力形式(GeneName, ChrNum)
            print("%s,%s") %  (gene_character['GeneName'], gene_character['ChrNum'])
        else:
            print("%s,plasmid") % gene_character['GeneName']



# #または、
# if len(sys.argv) <= 1:
#     print "Usage:match_regular <words>"
#     sys.exit()

# ni = str(sys.argv[1])   #読み込み

# print(ni)
