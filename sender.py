import random


def get_a2d_data():
    return random.randint(0, 4094)


def convert_a2d_to_amps(a2d_data: int):
    return round(a2d_data * 10 / 4094)


def get_temperature():
    return random.randint(0, 100)


def send_data_to_console():
    for line in range(50):
        print(f'Amps: {convert_a2d_to_amps(get_a2d_data())}, Temp: {get_temperature()}')


if __name__ == "__main__":
    send_data_to_console()
