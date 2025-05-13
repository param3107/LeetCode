import os
 
# Function to rename multiple files
def main():
   
    folder = os.getcwd()
    for count, filename in enumerate(os.listdir(folder)):
        if filename[0] == "0":
            os.rename(filename, "0" + filename)
 
# Driver Code
if __name__ == '__main__':
     
    # Calling main() function
    main()