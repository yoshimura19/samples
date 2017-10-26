#coding:utf-8
#スペルチェッカー

f = open("story.txt", 'r')
story_string = f.read()
vocabulary = open("dictionary.txt", "r").read()       #スペルチェック用辞書

def clean_text(text_string, special_characters,):    #clean func(文書,[',',..])
    cleaned_string = text_string
    for string in special_characters:
        cleaned_string = cleaned_string.replace(string, "") #""に置き換え
    cleaned_string = cleaned_string.lower()
    return(cleaned_string)

                                           #文書をトークンを単位にリスト化
def tokenize(text_string, special_characters, clean=False):
    if clean == True:
        cleaned_story = clean_text(text_string, special_characters)
        story_tokens = cleaned_story.split(" ")
    else:
        story_tokens = text_string.split(" ")
    return(story_tokens)

misspelled_words = []
clean_chars = [",", ".", "'", ";", "\n"]
tokenized_story = tokenize(story_string, clean_chars, clean=True)
tokenized_vocabulary = tokenize(vocabulary, clean_chars)

for ts in tokenized_story:
    if ts not in tokenized_vocabulary:
        misspelled_words.append(ts)
print(misspelled_words)


def spell_check(vocabulary_file, text_file, special_characters=[",",".","'",";","\n"]):
    misspelled_words = []
    story_string = open(text_file).read()
    vocabulary = open(vocabulary_file).read()

    tokenized_vocabulary = tokenize(vocabulary, special_characters) #clean=False
    tokenized_text = tokenize(story_string, special_characters, clean=True)

    for ts in tokenized_text:
        if ts not in tokenized_vocabulary and ts != "":
            misspelled_words.append(ts)
    return(misspelled_words)

final_misspelled_words = spell_check(text_file="story.txt", vocabulary_file="dictionary.txt")  #special=character=FALSE
print(final_misspelled_words)

