def get_rule2(id):
    new_id = "" 

    for i in range(len(id)):
        if not id[i].isalpha() and not id[i].isdigit():
            if not id[i] in ['.', '-', '_']:
               continue
        
        new_id += id[i]

    return new_id

def get_rule3(id):
    new_id = id

    while ".." in id:
        new_id.replace("..", ".")

    return new_id
    

def solution(new_id):
    answer = new_id.lower()
    new_id = new_id.lower()

    new_id = get_rule2(new_id)
    print("rule2", new_id)

    new_id = get_rule3(new_id)

    new_id = new_id.lstrip('.')
    new_id = new_id.rstrip('.')
    
    if new_id == "":
        new_id = 'a'

    if 16 <= len(new_id):
        new_id = new_id[0:15].rstrip(".")


    if len(new_id) <= 2:
        while len(new_id) < 3:
            new_id += new_id[-1]

    print(new_id)
    return new_id

if __name__ == "__main__":
    solution("123_.def")