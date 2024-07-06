# Computational Intelligence Archive
# @author Dwij Bavisi <dwij@dbavisi.net>
# Website: https://cia.dbavisi.net
#
# Implementation of File System utility classes in Python Programming Language.

from os import path, listdir, mkdir

class Directory:
  def __init__(self, abspath):
    if path.isdir(abspath):
      self.abspath = abspath
    elif path.isfile(abspath):
      self.abspath = path.dirname(abspath)
    else:
      raise FileNotFoundError(f"Directory {self.abspath} not found")
    self.name = path.basename(self.abspath)
    self._parent = path.dirname(self.abspath)
    self._subdirs = []
    self._files = []
    self.refresh()

  def refresh(self):
    self._subdirs = []
    self._files = []
    for item in listdir(self.abspath):
      if path.isdir(path.join(self.abspath, item)):
        self._subdirs.append(item)
      else:
        self._files.append(item)

  @property
  def parent(self):
    return Directory(self._parent)

  def has_subdir(self, name):
    return name in self._subdirs

  def subdir(self, name):
    if not self.has_subdir(name):
      raise FileNotFoundError(f"Directory {self.abspath}>{name} not found")
    return Directory(path.join(self.abspath, name))

  def has_file(self, name):
    return name in self._files

  def file(self, name):
    if not self.has_file(name):
      raise FileNotFoundError("File {self.abspath}>{name} not found")
    return File(path.join(self.abspath, name))

  def mkdir(self, name):
    if self.has_subdir(name):
      return self.subdir(name)
    newdir = path.join(self.abspath, name)
    mkdir(newdir)
    self._subdirs.append(name)
    return Directory(newdir)

  def stubfile(self, name):
    if self.has_file(name):
      return self.file(name)
    newfile = path.join(self.abspath, name)
    return File(newfile)

class File:
  def __init__(self, abspath):
    self.abspath = abspath
    self.name = path.basename(abspath)
    self._parent = path.dirname(abspath)

  @property
  def parent(self):
    return Directory(self._parent)

  def open(self, mode='r'):
    return open(self.abspath, mode)
