from testlib import run, expect
from itertools import chain
from random import randint

def test(i, n, m, friends):
  friendsString = "".join([f"{x[0]} {x[1]}\n" for x in friends])
  expected = sortUsers(n, m, friends)
  expectedString = " ".join([str(x) for x in expected]) + " "
  result = run("LeastNeighbours.exe", f"{n} {m}\n{friendsString}")
  try:
    expect(result[0]).toBe(0)
    expect(result[1]).toBe(expectedString)
  except AssertionError:
    print(f"\u001b[31mTest {i + 1} failed!\u001b[37m")
    print(f"Users: {n}, Friendships: {m}.")
    for x in friends: print(x)
    print(f"Expected: {expected}, Was: {result}")
    return False
  print(f"\u001b[32mTest {i + 1} passed!\u001b[37m")
  return True

# def sortUsers(n, m, friends):
#   cnt = [0 for i in range(n)]
#   for i, j in friends:
#     cnt[i] += 1
#     cnt[j] += 1
#   buckets = [[] for i in range(m + 1)]
#   for i, cnt in enumerate(cnt):
#     buckets[cnt].append(i)
#   res = list(chain(*buckets))
#   return res

def sortUsers(n, m, friends):
  cnt = [0 for i in range(n)]
  for i, j in friends:
    cnt[i] += 1
    cnt[j] += 1
  def key(e):
    return e[1]
  return [x[0] for x in sorted(list(enumerate(cnt)), key=key)]

def main():
  i = 0
  passed = 0
  failed = 0
  for n in range(2, 40):
    for m in range(int(((n + 1) * n) / 2)):
      friends = []
      a = b = 0
      for _ in range(m):
        a += 1
        if (a >= n):
          a = 0
          b += 1
        friends.append((a, b))
      if(test(i, n, m, friends)):
        passed += 1
      else:
        failed += 1
      i += 1
  print(f"Passed: {passed}/{i}, Failed: {failed}")

if __name__ == "__main__":
  main()