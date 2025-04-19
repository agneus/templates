def find_prefix_sums(a):
    n = len(a)
    prefix_sums = [0] * (n + 1)
    for i in range(n):
        prefix_sums[i + 1] = prefix_sums[i] + a[i]
    return prefix_sums

def find_diffs_array(arr):
    n = len(arr)
    diffs = [0] * (n - 1)
    for i in range(n - 1):
        diffs[i] = arr[i + 1] - arr[i]
    return diffs

def precalc(b):
    b = [0] + b  # add leading zero
    a = find_diffs_array(b)
    return a

def postcalc(a):
    final_b = find_prefix_sums(a)
    return final_b[1:]  # remove the leading zero

# --- Main ---
n = int(input())                          # size of array
b = list(map(int, input().split()))      # initial array

diff_arr = precalc(b)

queries_number = int(input())
for _ in range(queries_number):
    l, r, d = map(int, input().split())  # 0-based, [l, r)
    diff_arr[l] += d
    if r < n:
        diff_arr[r] -= d

final_b = postcalc(diff_arr)
print(*final_b)
