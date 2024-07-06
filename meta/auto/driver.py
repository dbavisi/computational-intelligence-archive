# Computational Intelligence Archive
# @author Dwij Bavisi <dwij@dbavisi.net>
# Website: https://cia.dbavisi.net
#
# Implementation of Metadata utility classes in Python Programming Language.

import json

from include.py.codebase.codebase import Codebase
from include.py.codebase.FS import Directory
from gather.py.gather import Gather

# meta/auto/driver.py
ROOT = Codebase(Directory(__file__).parent.parent.abspath)
GATHER = Gather(ROOT)
json.dump(GATHER.gather_metadata(),
          ROOT.subdir('meta').mkdir('raw').stubfile('metadata.json').open('w'),
          indent=2,
          separators=(',', ': '))
