import random

def random_list_int(length):
    buff_list = list()
    for i in range(0,length):
        buff_list.append(random.randint(0, 100))
    return buff_list

def main():
    random_list_int(10)

if __name__ == "__main__":
    main()
