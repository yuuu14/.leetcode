import random

def generate_number_with_probability(numbers, probabilities):
    # Check if the lengths of the inputs are equal
    assert len(numbers) == len(probabilities), "Lengths of numbers and probabilities must be equal"

    # Generate a random number between 0 and 1
    r = random.random()

    # Calculate the cumulative probabilities
    cum_probabilities = [sum(probabilities[:i+1]) for i in range(len(probabilities))]

    # Find the index of the first cumulative probability greater than r
    index = next(i for i, p in enumerate(cum_probabilities) if p > r)

    # Return the corresponding number
    return numbers[index]

def main():
    numbers = [1, 2, 3, 4, 5]
    probabilities = [0.1, 0.2, 0.3, 0.2, 0.2]
    print(generate_number_with_probability(numbers, probabilities))

if __name__ == "__main__":
    main()