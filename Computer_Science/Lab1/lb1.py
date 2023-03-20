import wikipedia

def is_page_valid(page):
    try:
        wikipedia.page(page)
    except Exception:
        return False
    return True

def is_language_valid(lang_form):
    if lang_form not in wikipedia.languages():
        print("no results")
        return False
    else:
        wikipedia.set_lang(lang_form)
        return True

def max_count_words(some_pages):
    max_len = 0
    wiki_title = ''
    for element in some_pages:
        if is_page_valid(element):
            words = len(wikipedia.page(element).summary.split())
            if words >= max_len:
                max_len = words
                wiki_title = wikipedia.page(element).title
        else:
            return False
    return [max_len, wiki_title]

def create_chain(some_pages):
    chain = [some_pages[0]]
    for i in range(len(some_pages)-1):
        links_on_page = wikipedia.page(some_pages[i]).links
        if some_pages[i+1] in links_on_page:
            chain += [some_pages[i+1]]
        else:
            for linker_page in links_on_page:
                if some_pages[i+1] in wikipedia.page(linker_page).links and is_page_valid(linker_page):
                    chain += [linker_page, some_pages[i+1]]
                    break
    return chain

pages = input().split(', ')
if is_language_valid(pages.pop()):
    print(f"{max_count_words(pages)[0]} {max_count_words(pages)[1]}")
    print(create_chain(pages))
