import shutil
import os
import argparse

def copy(source_dir, dest_dir):
    names = os.listdir(source_dir)
    for name in names:
        srcname = os.path.join(source_dir, name)
        #dstname = os.path.join(dest_dir, name)
        shutil.copy(srcname, dest_dir)
        print(srcname)

def main():
    parser = argparse.ArgumentParser(description='pass source folder and dest folder')
    parser.add_argument("source")
    parser.add_argument("destination")
    args = parser.parse_args()
    copy(args.source,args.destination)

if __name__ == '__main__':
    main()