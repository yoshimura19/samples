#coding:utf-8

f = open("dictionary.txt", "r")
vocabulary = f.read()

tokenized_vocabulary = vocabulary.split(" ")
#print(tokenized_vocabulary)

f2 = open("story.txt", "r")
story_string = f2.read()

# story_string = story_string.replace(".", "")
# story_string = story_string.replace(",", "")
# story_string = story_string.replace("'", "")
# story_string = story_string.replace("\n", "")
# story_string = story_string.replace(";", "")


def clean_text(text_string):
    cleaned_string = text_string.replace(".", "")
    cleaned_string = cleaned_string.replace(";", "")
    cleaned_string = cleaned_string.replace(",", "")
    cleaned_string = cleaned_string.replace("\n", "")
    cleaned_string = cleaned_string.replace("'", "")
    cleaned_string = cleaned_string.lower()
    return(cleaned_string)

cleaned_story = clean_text(story_string)
#print(cleaned_story)

def strip_text(text_string, strip_string, replacement_string):
    cleaned_string = ""
    cleaned_string = text_string.replace(strip_string, replacement_string)
    return(cleaned_string)


cleaned_story = ""
clean_chars = [",", ".", "'", ";", "\n"]
def clean_text(text_string, special_characters):
    cleaned_string = text_string
    for s_chara in special_characters:
        cleaned_string = cleaned_string.replace(s_chara, "")
    cleaned_string = cleaned_string.lower()
    return(cleaned_string)

cleaned_story = clean_text(story_string, clean_chars)
#print(cleaned_story)

cleaned_story = ""
def tokenize(text_string, special_characters):
    cleaned_story = clean_text(text_string, special_characters)
    story_tokens = cleaned_story.split(" ")
    return(story_tokens)

tokenized_story = tokenize(story_string, clean_chars)
#print(tokenized_story)


misspelled_words = []
clean_chars = [",", ".", "'", ";", "\n"]
tokenized_story = tokenize(story_string, clean_chars)
tokenized_vocabulary = tokenize(vocabulary, clean_chars)
for token in tokenized_story:
    #if token not in tokenized_vocabulary:
    if not(token in tokenized_vocabulary):
        misspelled_words.append(token)

print(misspelled_words)
