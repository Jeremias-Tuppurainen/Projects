def main(): #    0     1     2     3     4     5
    aikataulu = [630, 1015, 1415, 1620, 1720, 2000]
    a = int(input("Enter the time (as an integer): "))
    i = 0
    p = 0
    for numbers in aikataulu:
        if aikataulu[i] >= a:
            if p == 3:
                break
            print("The next buses leave:")
            for number in range(3):
                print(aikataulu[i])
                i += 1
                p += 1
                if i >= 6:
                    i = 0
        else:
            i += 1
            if a >= 2000:
                print("The next buses leave:")
                print(aikataulu[0])
                print(aikataulu[1])
                print(aikataulu[2])
                break





main()
'''
Enter the time (as an integer): 1000
The next buses leave:
1015
1415
1620

6.30
10.15
14.15
16.20
17.20
20.00

Enter the time (as an integer): 1800
The next buses leave:
2000
630
1015
'''