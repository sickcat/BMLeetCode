m, n = [int(_) for _ in str(input()).strip().split(' ')]
count_map = {}
value_list = []
conis = []
cans = []
for i in range(n):
    tmp = int(input())
    if tmp <= m:
        count_map[tmp] = 0
        value_list.append(tmp)
value_list.sort()

if value_list[0] != 1:
    print(-1)
else:
    while(len(cans) < m):
        max_c = -1
        add_value = -1
        for each in value_list:
            tmp_cans = []
            count = 0
            for i in cans:
                if i+each <= m and i + each not in cans and i+each not in tmp_cans:
                    count += 1;
                    tmp_cans.append(i+each)
            if each not in cans:
                count+=1
            if count > max_c:
                max_c = count
                add_value = each
        
        new_cans = []
        for i in cans:
            if i + add_value <= m:
                new_cans.append(i+add_value)
        if add_value not in cans:
            cans.append(add_value)
        count_map[add_value] += 1
        new_cans.extend(cans)
        cans = list(set(new_cans))

    ans = 0
    for each in value_list:
        ans += count_map[each]
    print(ans)