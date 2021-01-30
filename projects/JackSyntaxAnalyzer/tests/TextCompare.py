from termcolor import cprint


def get_actual_tokens(file):
    actual_tokens = []
    for line in file:
        actual_tokens.append(line.strip())
    return actual_tokens


def compare_text(file, expected):
    actual_tokens = get_actual_tokens(file)

    expected_tokens = [token.strip() for token in expected.strip().split('\n')]
    results = []

    for i in range(len(expected_tokens)):
        actual_token = actual_tokens[i]
        expected_token = expected_tokens[i]

        results.append(f"{actual_token} : {expected_token}")
        if actual_token != expected_token:
            print_result(results)
            cprint(f"Difference: {actual_token} : {expected_token}", "green")
            return False

    return True


def print_result(results):
    for result in results:
        print(result)
