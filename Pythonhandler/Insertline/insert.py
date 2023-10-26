def FileInsertTargetlineBeforeSourceline(filename, matchSource, targetSource):
    try:
        with open(filename, 'r+') as file:
            lines = file.readlines()
            foundmatchSource = False
            foundtargetSource = False
            linesBeforematchSource = []

            for line in lines:
                if matchSource in line:
                    foundmatchSource = True
                    break
                linesBeforematchSource.append(line)
                if targetSource in line:
                    foundtargetSource = True

            if foundmatchSource and not foundtargetSource:
                file.seek(0)
                file.truncate()

                for line in linesBeforematchSource:
                    file.write(line)

                file.write(targetSource + '\n')
                file.write(matchSource + '\n')

                for line in lines:
                    file.write(line)

                print(f"Inserted targetSource --> {targetSource} before {matchSource} in {filename}")
                return True
    except FileNotFoundError:
        print(f"Error: Unable to open the configuration file {filename}.")
    return False


def FileInsertTargetlineAfterSourceline(filename, matchSource, targetSource):
    try:
        with open(filename, 'r+') as file:
            lines = file.readlines()
            foundmatchSource = False
            foundtargetSource = False
            linesBeforematchSource = []
            linesAftermatchSource = []

            for line in lines:
                if matchSource in line:
                    foundmatchSource = True
                    linesBeforematchSource.append(line)
                else:
                    if foundmatchSource:
                        linesAftermatchSource.append(line)

                        if targetSource in line:
                            foundtargetSource = True

            if foundmatchSource and not foundtargetSource:
                file.seek(0)
                file.truncate()

                for line in linesBeforematchSource:
                    file.write(line)

                file.write(targetSource + '\n')

                for line in linesAftermatchSource:
                    file.write(line)

                print(f"Added targetSource --> {targetSource} to {filename}")
                return True
    except FileNotFoundError:
        print(f"Error: Unable to open the configuration file {filename}.")
    return False
