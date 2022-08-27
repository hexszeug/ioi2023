import subprocess
import tkinter as tk
from tkinter import filedialog
from os.path import exists

def main():
  lastFolder = ""
  with open("settings.yml") as f:
    for line in f:
      setting = [x.strip() for x in line.split(":")]
      if setting[0] == "lastFolder": lastFolder = setting[1]
  
  root = tk.Tk()
  root.withdraw()
  
  testProgramPath = filedialog.askopenfilename(initialdir=lastFolder)
  lastFolder = testProgramPath[:testProgramPath.rfind("/") + 1]
  fileName = testProgramPath[testProgramPath.rfind("/") + 1:]
  
  manualTestInput = False

  if exists(f"auto-gen-test-files/{fileName}.test"):
    tempIn = input("A cached test file was found. Do you want to run the test from it? (otherwise enter a manual test) [J/n] ")
    if tempIn == "n" or tempIn == "N":
      manualTestInput = True
  else:
    manualTestInput = True

  

  with open("settings.yml", "w") as f:
    f.write(f"lastFolder: {lastFolder}")

def run(command, stdin=""):
  process = subprocess.run(command, text=True, input=stdin, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
  return (process.returncode, process.stdout)

if __name__ == "__main__": main()