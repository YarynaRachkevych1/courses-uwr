import requests
from Prywatne import API_key

def get_info(start_requests):
    responses = []
    for (url_, headers_, params_) in start_requests:
        resp = requests.get(url_, headers=headers_, params=params_)
        responses.append(resp.json())
    return responses

request1 = ("https://wordsapiv1.p.rapidapi.com/words/fall/also",
            {"X-RapidAPI-Key": API_key,
	        "X-RapidAPI-Host": "wordsapiv1.p.rapidapi.com"},
            {})

request2 = ("https://wft-geo-db.p.rapidapi.com/v1/geo/cities/Q84/nearbyCities",
            {"X-RapidAPI-Key": API_key,
	        "X-RapidAPI-Host": "wft-geo-db.p.rapidapi.com"},
            {"radius":"10"})

requests_ = [request1, request2]

info = get_info(requests_)

what_about = ["Czescia jakich fraz jest podane slowo: ",
            "Informacja o miescie, podanego jako numer z WikiData oraz o miastach w poblizu: "]

for i in range(len(requests_)):
    print(what_about[i], '\n', info[i], "\n"*2)