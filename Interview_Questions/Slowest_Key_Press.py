def slowestKey(keyTimes):

    keyTimes = [[chr(k[0] + 97), k[1]] for k in keyTimes]                   

    longest_key = None

    longest_duration = None   

    for i in range(len(keyTimes)):

        if i == 0:

            start = 0

        else:

            start = keyTimes[i-1][1]

        end = keyTimes[i][1]

        char = keyTimes[i][0]

        interval = end - start

        if not longest_duration or interval > longest_duration:

            longest_duration = interval

            longest_key = char

    return longest_key