import traceback

# Recursive function that returns the sum of the previous 
# 2 numbers given a position "n".
#
# The results are stored in memory to access them 
# and not recalculate values (Memoization).
# Memo must be initialized the first 2 values to 1 !
def fib(n, memo):

  # If n is in memo, the value calculated above is returned
  if n in memo:
    return memo[n]

  # Stores the sum of the previous 2 numbers in memo
  memo[n] = fib(n-1, memo) + fib(n-2, memo)

  # Returns the value in memo corresponding to n
  return memo[n]

  
# Stores the values of the sequence in the memo dictionary 
# and prints memo
def fibSequence(n):
  memo = {0:1, 1:1}
  
  fib(n, memo);

  print( memo)


# Stores the values of the sequence in the memo dictionary and 
# prints the sum of the memo values
def fibSum(n):
  memo = {0:1, 1:1}
  
  fib(n, memo);
  
  amount = sum(memo.values())

  print(amount)
  
# Execute the solution function with test cases and verify that the response is the same as expected
def main():
  test_cases = [3, 5, 7, 9, 13]
  expected = [3, 8, 21, 55, 377]

  for i in range(len(test_cases)):
        solution = None
        try:
            test_case = test_cases[i]

            memo = {0:1, 1:1}
          
            solution = fib(test_case, memo)
          
            assert solution == expected[i]
            print("OK")
        except AssertionError as assert_error:
            print(f"Error, test {test_cases[i]}, expected {expected[i]}, calculated {solution}")            
        except Exception as error:
            print(traceback.format_exc())

main()

