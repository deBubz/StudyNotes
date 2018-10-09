# CH7

## 1 txt to csv /replace space with comma

``cat file.txt | tr -s '[:blank:]' ',' > changed.csv``

## 2 sort text

``sort file.txt >> new.txt``

## 3 get first word of list

``awk '{print $1}' file >> output,txt``
