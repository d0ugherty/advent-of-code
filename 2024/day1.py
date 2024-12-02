import csv
import sys

def sort_list(input_list: list) -> list:
    for idx, value in enumerate(input_list):
        small_idx = idx
        unsorted_idx = small_idx + 1
        while (unsorted_idx < len(input_list)):

            if input_list[unsorted_idx] < input_list[small_idx]:
                small_idx = unsorted_idx

            unsorted_idx = unsorted_idx + 1

        temp = input_list[idx]
        input_list[idx] = input_list[small_idx]
        input_list[small_idx] = temp

def extract_ids(id_list: list) -> list:
    # Get lists of IDs
    list_one = [int(row[0]) for row in id_list]
    list_two = [int(row[3]) for row in id_list]

    return list_one, list_two

def get_list_from_file(file_name: str) -> list:
    file = open(file_name)
    id_list = []
    with file as f:
        file_reader = csv.reader(f, delimiter=' ')
        for row in file_reader:
            id_list.append(row)

    return id_list

def get_total_distance(list_one: list, list_two: list) -> int:
    return sum(abs(a - b) for a, b in zip(list_one, list_two))

def sim_score(list_one: list, list_two: list) -> int:
   return sum(value * list_two.count(value) for value in list_one)

if __name__ == '__main__':
    print(sys.argv[1])
    id_list = get_list_from_file(sys.argv[1])
    # Sort lists
    list_one, list_two = extract_ids(id_list)
    sort_list(list_one)
    sort_list(list_two)
    total_distance = get_total_distance(list_one, list_two)
    print(total_distance)
    print(sim_score(list_one, list_two))