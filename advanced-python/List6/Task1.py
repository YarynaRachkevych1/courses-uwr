import re
import requests

seen_pages = []
re_compiler = re.compile('http://' + '([a-zA-Z]+.)*[a-zA-Z]+')

def crawl(init_page, distance, f_action):
    global seen_pages
    global re_compiler
    if distance > 0 and init_page not in seen_pages:
        try:
            text = requests.get(init_page).text
            seen_pages.append(init_page)
            yield init_page, f_action(text)
            for url in set(
                    url.group() for url in 
                    re_compiler.finditer(text)
                ):
                res_gen = crawl(url, distance - 1, f_action)
                for page, res in res_gen:
                    yield page, res
        except:
            pass

for url, wynik in crawl(
        'http://www.ii.uni.wroc.pl', 2,
        lambda tekst : 'Python' in tekst
    ):
    print(f"{url}: {wynik}")