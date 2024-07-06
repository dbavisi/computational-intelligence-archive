# Computational Intelligence Archive
# @author Dwij Bavisi <dwij@dbavisi.net>
# Website: https://cia.dbavisi.net
#
# Implementation of Metadata Gathering utility classes in Python Programming Language.

from include.py.codebase.codebase import Codebase

class Gather:
  def __init__(self, codebase: Codebase):
    self.codebase = codebase

  def gather_metadata(self):
    metadata = {}
    metadata['structure'] = self.gather_structure_metadata(self.codebase)

    return metadata

  def gather_structure_metadata(self, root):
    metadata = {}
    for structure in root.subdir('structure')._subdirs:
      metadata[structure.name] = self.gather_structure_implementation_metadata(structure)

    return metadata

  def gather_structure_implementation_metadata(self, structure):
    metadata = {}
    print(structure.subdir('implementation')._subdirs)
    for implementation in structure.subdir('implementation')._subdirs:
      metadata[implementation.name] = self.gather_implementation_metadata(implementation)

    return metadata

  def gather_implementation_metadata(self, implementation):
    metadata = {}
    metadata['languages'] = implementation._subdirs

    return metadata
