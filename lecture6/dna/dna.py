import csv
import sys


def main():
    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("You should put 2 command line arguments.")
    # TODO: Read database file into a variable
    dna_database = []
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            dna_database.append(row)
        str_list = reader.fieldnames
        str_list.remove("name")
    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2]) as file:
        dna_sequece = file.read()
    # TODO: Find longest match of each STR in DNA sequence
    longest_match_str = dict()
    for str_subsequece in str_list:
        longest_match_str[str_subsequece] = str(
            longest_match(dna_sequece, str_subsequece)
        )
    # TODO: Check database for matching profiles
    print_return = "No match"
    for row in dna_database:
        name = row.pop("name")
        if row == longest_match_str:
            print_return = name
    print(print_return)
    sys.exit(0)


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:
            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
