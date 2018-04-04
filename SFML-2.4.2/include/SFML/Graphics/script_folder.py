import re
import os

files = os.listdir(os.getcwd())
headers = filter(lambda x: x.endswith('.hpp'), files)
for file_name in headers:
  with open(file_name, 'r') as f:
    content = f.read()
    lines = content.split('\n')
    content = ''
    for line in lines:
      head_cur_dir = re.search(r'<SFML/\w+\.hpp>', line)
      head_other_dir = re.search(r'<SFML/\w+/\w+\.hpp', line)
      if head_other_dir:
        line = line.replace('<', '"')
        line = line.replace('>', '"')
        line = line.replace('SFML', '..')
      if head_cur_dir:
        line = line.replace('<', '"')
        line = line.replace('>', '"')
        line = line.replace('SFML/', '../')
      content += line + '\n'
  with open(file_name, 'w') as f:
    f.write(content)