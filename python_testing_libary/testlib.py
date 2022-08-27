import subprocess

def run(command, stdin=""):
  process = subprocess.run(command, text=True, input=stdin, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
  return (process.returncode, process.stdout)

class AsserionError(RuntimeError): ...

class Assertion:
  def __init__(self, value):
    self.value = value

  def toBe(self, expected):
    if (self.value != expected):
      raise AssertionError(f"Assertion failed! Expected: {expected}, Was: {self.value}.")

def expect(value):
  return Assertion(value)