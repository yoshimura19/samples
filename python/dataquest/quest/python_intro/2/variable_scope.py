#coding:utf-8

#hand_size_dataset
institution = ['Alabama Agricultural & Mechanical University', 'Alabama State University', 'Auburn University', 'Auburn University Montgomery', 'Birmingham Southern College', 'Concordia College Alabama', 'Faulkner University', 'Huntingdon College', 'Jacksonville State University', 'Jefferson State Community College']
state = ['AL', 'AL', 'AL', 'AL', 'AL', 'AL', 'AL', 'AL', 'AL', 'AL']
city = ['Normal', 'Montgomery', 'Auburn', 'Montgomery', 'Birmingham', 'Selma', 'Montgomery', 'Montgomery', 'Jacksonville', 'Birmingham']
borrower_default_count_240 = [1606, 1567, 269, 184, 93, 75, 52, 88, 12, 5]
principal_outstanding_240 = [954821, 1410608, 747267, 457312, 240798, 52874, 115167, 143488, 20745, 7204]

#built-in functions
def find_average(column):
    length = len(column)
    total = sum(column)
    return total / length

def find_length(column):
    length = len(column)
    return length

length = len(borrower_default_count_240)
average = find_average(principal_outstanding_240)
principal_length = find_length(principal_outstanding_240)
print(average, principal_length)

total = 10
def find_total(column):
    total = total + sum(column)
    return total           #we cannot change a value of global scope
#print(find_total(principal_outstanding_240))
