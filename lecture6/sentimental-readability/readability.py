def main():
    text = str(input("Text: "))
    cl = count_letters(text)
    cw = count_words(text)
    cs = count_sentences(text)
    index = calculate_index(cl, cw, cs)

    if index < 1:
        print("Before Grade 1")
    elif index < 16:
        print(f"Grade {index}")
    elif index >= 16:
        print("Grade 16+")


def count_letters(text: str) -> int:
    count = 0
    for character in text:
        if (ord(character) >= 65 and ord(character) <= 90) or (
            ord(character) >= 97 and ord(character) <= 122
        ):
            count += 1
    return count


def count_words(text: str):
    return list(text).count(" ") + 1


def count_sentences(text: str):
    sentences_count = 0
    for point in [".", "!", "?"]:
        point_count = list(text).count(point)
        sentences_count += point_count
    return sentences_count


def calculate_index(letters_count, words_count, sentences_count):
    L = letters_count / words_count * 100
    S = sentences_count / words_count * 100

    return round(0.0588 * L - 0.296 * S - 15.8)


if __name__ == "__main__":
    main()
