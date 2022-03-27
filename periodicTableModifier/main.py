import json
with open('ptable.json') as data_file:
  data = json.load(data_file)
desired = ['name', 'atomic_mass', 'category']
for element in data['elements']:
  change = False
  firstTime = True
  while (change or firstTime):
    change = False
    if (firstTime):
      firstTime = False
    for individual_elem in element:
      if individual_elem not in desired:
        del element[individual_elem]
        change = True
        break
with open('rev_ptable.json', 'w') as data_file:
  data = json.dump(data, data_file, indent = 4)