def main():
    price = int(input("Purchase price: "))
    given = int(input("Paid amount of money: "))
    money = given - price
    rahat = [10, 5, 2, 1]
    change = [0, 0, 0, 0]
    i = 0
    while money > 0:
        biggest_money = rahat[i]
        remainder = money - biggest_money
        if remainder >= 0:
            money = remainder
            change[i] = change[i] + 1
        else:
            i = i + 1

    if all(v == 0 for v in change):      # if change[0] == 0 and change[1] == 0 and change[2] == 0 and change[3] == 0:
        print("No change")
    else:
        print("Offer change:")
        if change[0] > 0:
            print(change[0], "ten-euro notes")
        if change[1] > 0:
            print(change[1], "five-euro notes")
        if change[2] > 0:
            print(change[2], "two-euro coins")
        if change[3] > 0:
            print(change[3], "one-euro coins")

main()

# Purchase price: 11
# Paid amount of money: 50
# Offer change:
# 3 ten-euro notes
# 1 five-euro notes
# 2 two-euro coins