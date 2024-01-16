def main():
    card_number = int(input("Number: "))

    str_card_number = str(card_number)
    card_length = len(str_card_number)

    if not is_valid_credit_card_number(str_card_number):
        print("INVALID")
        return
    if is_amex(str_card_number, card_length):
        print("AMEX")
        return
    if is_mastercard(str_card_number, card_length):
        print("MASTERCARD")
        return
    if is_visa(str_card_number, card_length):
        print("VISA")
        return

    print("INVALID")


def is_valid_credit_card_number(str_card_number: str) -> bool:
    check_sum = 0
    for index, digit in enumerate(str_card_number[::-1]):
        digit = int(digit)
        if int(index % 2) == 1:
            digit *= 2
        check_sum += int(digit / 10 + digit % 10)
    if check_sum % 10 != 0:
        return False
    return True


def is_amex(str_card_number: str, card_length: int) -> bool:
    first_two_digits = str_card_number[:2]
    if first_two_digits in ("34", "37") and card_length == 15:
        return True
    return False


def is_mastercard(str_card_number: str, card_length: int) -> bool:
    first_two_digits = str_card_number[:2]
    if int(first_two_digits) in range(51, 56) and card_length == 16:
        return True
    return False


def is_visa(str_card_number: str, card_length: int) -> bool:
    first_digit = str_card_number[0]
    if first_digit == "4" and (card_length in (13, 16)):
        return True
    return False


if __name__ == "__main__":
    main()
