# Computational Intelligence Archive
# @author Dwij Bavisi <dwij@dbavisi.net>
# Website: https://cia.dbavisi.net
#
# Implementation of Codebase Organization utility classes in Python Programming Language.

from .FS import Directory

class Codebase(Directory):
  def __init__(self, root):
    super().__init__(root)

  def has_structure(self, name):
    return self.subdir('structure').has_subdir(name)

  def structure(self, name):
    if not self.has_structure(name):
      raise FileNotFoundError("Data structure {name} not found")
    return Structure(self.subdir('structure').subdir(name).abspath, name)

class Structure(Codebase):
  def __init__(self, root, structure):
    super().__init__(root)
    self.structure = structure

  def has_implementation(self, name, lang):
    if not self.subdir('implementation').has_subdir(name):
      return False
    return self.subdir('implementation').subdir(name).has_subdir(lang)

  def implementation(self, name, lang):
    if not self.has_implementation(name, lang):
      raise FileNotFoundError("Implementation {self.structure}, {name}, {lang} not found")
    return self.subdir('implementation').subdir(name).subdir(lang)
