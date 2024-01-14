def main():
    while True:
        try:
            height = int(input("Height: "))
        except Exception:
            continue
        if height >= 1 and height <= 8:
            print_pyramid(height)
            break


def print_bricks(n: int):
    for _ in range(n):
        print("#", end="")


def print_spaces(n: int):
    for _ in range(n):
        print(" ", end="")


def print_pyramid(height: int):
    for floor in range(1, height + 1):
        print_spaces(height - floor)
        print_bricks(floor)
        print("  ", end="")
        print_bricks(floor)
        print()


if __name__ == "__main__":
    main()
