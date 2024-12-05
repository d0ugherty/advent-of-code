import sys
import re


def read_file(file_name: str) -> list:
    with open(file_name) as file:
        text = file.read()
        return text

def get_total(instructions: list) -> int:
   # print(instructions)
    number_strings = [re.findall("[0-9]+,[0-9]+", instruction)[0] for instruction in instructions]
    
    total = 0

    for n_s in number_strings:
        split_list = n_s.split(',')
        total += int(split_list[0]) * int(split_list[1])
        
    return total

def parse_do_instructions(file_text: str) -> list:
    sub_strings = file_text.split('do')

    instructions = []

    for sub_str in sub_strings:
        if "n't" in sub_str:
            continue
        else:
            print(sub_str + '\n')
            matches = re.findall("mul\([0-9]+,[0-9]+\)", sub_str)
            instructions.append(matches)
            print(f'APPENDED: {matches} \n')


    return  [instruction for instruction_sublist in instructions for instruction in instruction_sublist]


if __name__ == '__main__':
    file_name = sys.argv[1]
    file_text = read_file(file_name)

    # Part One
    mult_instructions = re.findall("mul\([0-9]+,[0-9]+\)", file_text)
    print(get_total(mult_instructions))

    # Part Two
    #text_til_do_ins = re.findall('^.*?(?=do)', file_text)[0]
    #first_instructions = re.findall("mul\([0-9]+,[0-9]+\)", text_til_do_ins)

    #until_do_total = get_total(first_instructions)
    instructions = parse_do_instructions(file_text)
    #print(instructions)
    print(get_total(instructions))

    

    

