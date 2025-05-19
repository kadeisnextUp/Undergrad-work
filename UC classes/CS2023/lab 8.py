# -*- coding: utf-8 -*-
"""
Created on Sun Mar 16 12:23:11 2025

@author: Kaden Sawyer
"""

_author_ = "Kaden Sawyer"
_credits_ = ["none"]
_email_ = "sawyerkd@mail.uc.edu"

## Lab 8: Trees  ##
# Four Required Questions 


# pyTunes
def make_pytunes(username):
    """Return a pyTunes tree as shown in the diagram with USERNAME as the value
    of the root.

    >>> pytunes = make_pytunes('i_love_music')
    >>> print_tree(pytunes)
    i_love_music
      pop
        justin bieber
          single
            what do you mean?
        2024 pop mashup
      trance
        darude
          sandstorm
    """
#RQ1    "*** YOUR CODE HERE ***"
    #just creating the tree from the diagram
    return tree(username, [
        tree('pop', [
            tree('justin bieber', [
                tree('single', [
                    tree('what do you mean?')
                ])
            ]),
            tree('2024 pop mashup')
        ]),
        tree('trance', [
            tree('darude', [
                tree('sandstorm')
            ])
        ])
    ])
    


def num_songs(t):
    """Return the number of songs in the pyTunes tree, t.

    >>> pytunes = make_pytunes('i_love_music')
    >>> num_songs(pytunes)
    3
    """
#RQ2    "*** YOUR CODE HERE ***"
    """ if the tree has no branches retrun 1 otherwise recusively call the 
    function to count the number of songs in the tree
    
    """
    if is_leaf(t):
        return 1;
    return sum(num_songs(k) for k in branches(t))

def add_song(t, song, category):
    """Returns a new tree with SONG added to CATEGORY. Assume the CATEGORY
    already exists.

    >>> indie_tunes = tree('indie_tunes',
    ...                  [tree('indie',
    ...                    [tree('vance joy',
    ...                       [tree('riptide')])])])
    >>> new_indie = add_song(indie_tunes, 'georgia', 'vance joy')
    >>> print_tree(new_indie)
    indie_tunes
      indie
        vance joy
          riptide
          georgia

    """
#RQ3    "*** YOUR CODE HERE ***"\
    #base case: if the root is the category then add the song to the tree
    if root(t) == category:
        return tree(root(t), branches(t) + [tree(song)])
    #recusively call the function to find the right category and add the song
    return tree(root(t), [add_song(k, song, category) for k in branches(t)])

# Tree ADT
def tree(root, branches=[]):
    for branch in branches:
        assert is_tree(branch), 'branches must be trees'
    return [root] + list(branches)

def root(tree):
    return tree[0]

def branches(tree):
    return tree[1:]

def is_tree(tree):
    if type(tree) != list or len(tree) < 1:
        return False
    for branch in branches(tree):
        if not is_tree(branch):
            return False
    return True

def is_leaf(tree):
    return not branches(tree)

def print_tree(t, indent=0):
    """Print a representation of this tree in which each node is
    indented by two spaces times its depth from the entry.

    >>> print_tree(tree(1))
    1
    >>> print_tree(tree(1, [tree(2)]))
    1
      2
    >>> numbers = tree(1, [tree(2), tree(3, [tree(4), tree(5)]), tree(6, [tree(7)])])
    >>> print_tree(numbers)
    1
      2
      3
        4
        5
      6
        7
    """
    print('  ' * indent + str(root(t)))
    for b in branches(t):
        print_tree(b, indent + 1)

def copy_tree(t):
    """Returns a copy of t. Only for testing purposes.

    >>> t = tree(5)
    >>> copy = copy_tree(t)
    >>> t = tree(6)
    >>> print_tree(copy)
    5
    """
    return tree(root(t), [copy_tree(b) for b in branches(t)])


def delete(t, target):
    """Returns the tree that results from deleting TARGET from t. If TARGET is
    a category, delete everything inside of it.

    >>> my_account = tree('kpop_king',
    ...                    [tree('korean',
    ...                          [tree('gangnam style'),
    ...                           tree('wedding dress')]),
    ...                     tree('pop',
    ...                           [tree('t-swift',
    ...                                [tree('blank space')]),
    ...                            tree('uptown funk'),
    ...                            tree('see you again')])])
    >>> new = delete(my_account, 'pop')
    >>> print_tree(new)
    kpop_king
      korean
        gangnam style
        wedding dress
    """
 #RQ4   "*** YOUR CODE HERE ***"
    """ if the root is the target return nothing becuase the whole tree would
     be deleted
     
    """
    if root(t) == target: 
        return None 
    #recusively call the function to delete the target in the tree
    result = [delete(k, target) for k in branches(t)]
    #return the new tree with the target deleted
    return tree(root(t), [k for k in result if k is not None])

import doctest
if __name__ == "__main__":
  doctest.testmod(verbose=True)
               