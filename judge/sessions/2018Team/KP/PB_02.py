def maxIDX(l)->int:
  return l.index(max(l))

def minIDX(l)->int:
  l_idx = maxIDX(l)
  lmin = l[l_idx]
  for idx in range(len(l)):
    if (l[idx] < lmin and l[idx] > 0):
      l_idx = idx
      lmin = l[idx]
  return l_idx


if __name__ == "__main__":
    count = int(input())
    for i in range(count):
        inp = list(map(int, input().split()))
        num_pings = inp[0]
        players = list(map(int, input().split()))
        pings = list(map(int, input().split()))
        sad = 0
        max_player = maxIDX(players)
        max_ping = maxIDX(pings)
        for i in range(num_pings):

          if (players[max_player] > pings[max_ping]):
            # use max player and min ping
            sad += players[max_player]
            min_ping = minIDX(pings)
            # print("max player " + str(players[max_player]))
            # print("min ping " + str(pings[min_ping]))

            players[max_player] -= 1
            pings[min_ping] -= 1
          else:
            # use max ping and min player
            sad += pings[max_ping]
            min_player = minIDX(players)
            # print("min player " + str(players[min_player]))
            # print("max ping " + str(pings[max_ping]))

            players[min_player] -= 1
            pings[max_ping] -= 1
          
          max_player = maxIDX(players)
          max_ping = maxIDX(pings)

          if (players[max_player] <= 0 or pings[max_ping] <= 0):
            break
        print(sad)
