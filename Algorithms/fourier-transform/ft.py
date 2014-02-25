import numpy as np

def dft(x):
    """input x is a vector a complex numbers x0, ..., xN-1 of size N
    >>> x = np.random.random(1024)
    >>> np.allclose(dft(x), np.fft.fft(x))
    True
    """
    N = len(x)
    ret = []
    for i in range(N):
        """update Xk
        """
        realsum = 0
        imgsum = 0
        for n in range(N):
            real = np.cos(-2 * np.pi * i * n / N)
            img = np.sin(-2 * np.pi * i * n / N)
            realsum += x[n] * real
            imgsum += x[n] * img
        ret.append(complex(realsum, imgsum))
    return ret

def fft(x):
    """input x is a vector of a complex number x0, ... , xN-1 of size N
    >>> x = np.random.random(1024)
    >>> np.allclose(fft(x), np.fft.fft(x))
    True
    """
    N = len(x)
    if N  % 2 > 0:
        raise ValueError("Size of x should be a power of 2.")
    elif N <= 32:
        return dft(x)
    even = fft(x[::2])
    odd = fft(x[1::2])
    return [even[k] + np.exp(-2j * np.pi * k / N) * odd[k] for k in range(N / 2)] + \
            [even[k] - np.exp(-2j * np.pi * k / N) * odd[k] for k in range(N / 2)]

if __name__ == '__main__':
    import doctest
    doctest.testmod()
