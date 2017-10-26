#coding: utf8
import urllib2, sys, random
import xml.etree.ElementTree as etree

try: word = sys.argv[1]
except: word = '機械学習' # デフォルト検索ワード

try: option = sys.argv[2]
except: option = None

try: N = int(sys.argv[3])
except: N = 6

def links(word):
    try:
        word = word.replace(' ', '_')
        word = word.encode('utf_8')
    except:
        pass

    url = (
        'http://ja.wikipedia.org/w/api.php'
        '?format=xml&action=query&prop=links&pllimit=max&titles=%s'
    )
    resp = urllib2.urlopen(url % word).read()

    output = []
    tree = etree.fromstring(resp)

    try: plcont = tree.find('.//links').get('plcontinue')
    except: plcont = None

    while True:
        for link in tree.findall('.//pl'):
            if link.get('ns') == '0':
                output.append(link.get('title').encode('utf_8'))
        if plcont is None:
            break
        else:
            nextpage = url % word + '&plcontinue=%s' % plcont.encode('utf_8')
            resp = urllib2.urlopen(nextpage).read()
            tree = etree.fromstring(resp)
            try: plcont = tree.find('.//links').get('plcontinue')
            except: plcont = None

    return output

output = links(word)

if option == 'random':
    words = []
    for i in range(N):
        words.append(word)
        output = links(word)
        if len(output) == 0 or i == N-1:
            break
        word = output[random.randint(0, len(output)-1)]
    print ' -> '.join(words) + ', %s chains.' % len(words)
elif option == 'break':
    for o in output:
        print o
    print len(output), 'links.'
else:
    print ', '.join(output)
    print len(output), 'links.'
