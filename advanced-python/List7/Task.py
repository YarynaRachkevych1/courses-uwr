import re
import requests
import threading

seen_pages = []
re_compiler = re.compile('http://' + '([a-zA-Z]+.)*[a-zA-Z]+')

def crawl(init_page, distance, f_action):
    if distance > 0 and init_page not in seen_pages:
        try:
            text = requests.get(init_page).text
            seen_pages.append(init_page)
            yield init_page, f_action(text)

            threads = []
            results = []

            def crawl_results(args, results_list):
                for result in crawl(*args):
                    results_list.append(result)

            for url in set(
                    url.group() for url in 
                    re_compiler.finditer(text)
                    ):
                threads.append(threading.Thread(
                    target= crawl_results,
                    args= ((url, distance - 1, f_action), results)))
                
            [th.start() for th in threads]
            [th.join() for th in threads]
            yield from results
            
        except:
            pass

for url, wynik in crawl(
        'http://www.ii.uni.wroc.pl', 2,
        lambda tekst : 'Python' in tekst):
    print(f"{url}: {wynik}")