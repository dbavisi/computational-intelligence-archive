# Computational Intelligence Archive
# @author Dwij Bavisi <dwij@dbavisi.net>
# Website: https://cia.dbavisi.net
#
# Implementation of Metadata Gathering utility classes in Python Programming Language.

from include.py.codebase.codebase import Codebase, Structure

class Gather:
  def __init__(self, codebase: Codebase):
    self.codebase = codebase

  def gather_metadata(self):
    metadata = {}
    metadata['structure'] = self.gather_structure_metadata()

    return metadata

  def gather_structure_metadata(self):
    metadata = {}
    for structure in self.codebase.subdir('structure')._subdirs:
      metadata[structure] = self.gather_structure_implementation_metadata(
        self.codebase.structure(structure))

    return metadata

  def gather_structure_implementation_metadata(self, structure: Structure):
    metadata = {}
    for implementation in structure.subdir('implementation')._subdirs:
      metadata[implementation] = self.gather_implementation_metadata(
        structure.subdir('implementation').subdir(implementation))

    return metadata

  def gather_implementation_metadata(self, implementation):
    metadata = {}
    metadata['languages'] = implementation._subdirs

    return metadata
