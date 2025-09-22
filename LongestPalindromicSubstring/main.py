

"""
description of problem:
- given a string 's' return the *longest* palindromic subspring in s
- ex: s = "babad" return "bad"

initial thoughts:
- go over the string, looking for palidromes, save them and then search through
the palendromes for the longest one and return it
link: https://leetcode.com/problems/longest-palindromic-substring/
"""

def main():
    """ driver program """
    test_string = "this is a testset lal."
    print(find_palendromes(test_string))
    


def find_palendromes(in_s):
    """ gonna look throught a string and return a list of all the palendromes """

    out = list(list())

    for i in range(0, len(in_s)):
        # if in_s[i] == in_s[i+1] and in_s[i+1] not => len(in_s):
        #     # completes example two (not complete)
        #     out.append(in_s[i:i+1])
        for j in range(0, len(in_s) - i):
            # completes example one
            if in_s[i - j] == in_s[i + j]:
                out.append(in_s[i-j:i+j+1])
            else:
                break
    
    return out


if __name__ == "__main__":
    main()