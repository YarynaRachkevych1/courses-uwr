# Po uruchomieniu proszę chwilkę poczekać.
import requests
import matplotlib.pyplot as plt

# generowanie url dla pobrania danych z każdego dnia za miesiąc odpowieniego roku
def gen_url(year, month):
    return "http://api.nbp.pl/api/exchangerates/rates/c/usd/"+year+"-"+month+"-01/"+year+"-"+month+"-28/"

# wyczytywanie wartości z odpowiedzi o podanym polu
def get_value(resp, field):
    try:
        value = resp[field]
        return value
    except:
        pass

def get_info_month(url):
    resp = requests.get(url)
    data_json = resp.json()
    for rates_obj in data_json.get('rates', []):
        yield rates_obj


def frange(fr, to, st):
    while fr < to:
        yield fr
        fr += st

def calculate_bid_ask(year):
    months = ['01', '02', '03', '04', '05', '06', '07', '08', '09', '10', '11', '12']
    bid = []
    ask = []

    for m in months:
        url = gen_url(year, m)

        info = get_info_month(url)
        info1 = get_info_month(url)

        bid_list = [get_value(i, 'bid') for i in info]
        ask_list = [get_value(i, 'ask') for i in info1]
    
        # wyliczamy średnią
        bid_val = sum(bid_list) / len(bid_list)
        ask_val = sum(ask_list) / len(ask_list)

        bid.append(bid_val)
        ask.append(ask_val)
    
    return bid, ask

fig, (axs1, axs2) = plt.subplots(2, figsize=(7, 7.5))
fig.canvas.manager.set_window_title('Kurs dolara do złotego')

bid_2020 = calculate_bid_ask('2020')[0]
ask_2020 = calculate_bid_ask('2020')[1]

xs = [i for i in frange(0, len(bid_2020), 1)]

axs1.set_title('Dane z 2020 roku:')
axs1.plot(xs, bid_2020, color = '#a7c4f2')
axs1.plot(xs, ask_2020, color = '#4d6c9e')
axs1.legend(['kupno', 'sprzedaż'])


bid_2015 = calculate_bid_ask('2015')[0]
ask_2015 = calculate_bid_ask('2015')[1]

axs2.set_title('Dane z 2015 roku:')
axs2.plot(xs, bid_2015, color = '#ec91f2')
axs2.plot(xs, ask_2015, color = '#990aa3')
axs2.legend(['kupno', 'sprzedaż'])

sub_bid = [abs((bid_2020[i] - bid_2015[i]) / bid_2015[i]) for i in range(12)]
sub_ask = [abs((ask_2020[i] - ask_2015[i]) / ask_2015[i]) for i in range(12)]
plt.show()