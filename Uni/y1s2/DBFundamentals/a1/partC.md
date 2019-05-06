# Part C Logical Design

## Schema Conversion and Normlisation

## NOTES

1. Logical Design/ Schema Conversion
   - Convert ERD into a set of relational Tables in this format

```md
TableName(<u>Identifyer<ul>, non key attr, fk*)
ForeignKey references OtherTable
```

2. Logical Design/ Normalisation
   1. ID and list Functional FD and state which fd is determined based on which BR/Forms of your case study.
      - Use the format `X -> Y`
      - `Determinant -> Dependent`
   2. Use FD to determine highes normal form for each table/relation in previous part.
      - Also Justify your choice
      - Normalise all table till they are BCNF (or 3rd?)
      - Document each detail of the nomalzation(or 3rd?)
3. Reflecton on your design and Lesson learnt
4. Structure
   1. Revised BR and Assumption
   2. Revised ERD of Part B
   3. Relations
   4. List of FD related to each BR
   5. Normalisation
   6. Reflection

**NOTE** Normalization step by step