import json 

def extractor():
    elements = ''
    with open("assets/ptable.json", 'r') as data:
        elements = json.load(data)

    rev_elem = [[-1, -1]]
    for element in elements["elements"]:
        rev_elem.append([element['name'], element['category']])

    return rev_elem