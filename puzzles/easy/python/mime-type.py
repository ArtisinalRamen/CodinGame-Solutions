# https://www.codingame.com/ide/puzzle/mime-type
n: int = int(input())  # Number of elements which make up the association table.
q: int = int(input())  # Number Q of file names to be analyzed.
assocTable = {}
UNKNOWN = "UNKNOWN"

for i in range(n):
    ext, mt = [str(s) for s in input().split()]
    assocTable.update({ext.lower(): mt})

out = ""
extSepIndex: int = 0
for i in range(q):
    fname: str = input()  # One file name per line.
    extSepIndex = fname.rfind(".") # -1 If "." not found, else index.
    if extSepIndex == -1:
        print(UNKNOWN)
        continue

    out = assocTable.get(fname[extSepIndex + 1:].lower())
    if out == None:
        print(UNKNOWN)
        continue

    print(out)