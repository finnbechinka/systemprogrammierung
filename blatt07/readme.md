# Blatt 07: Ringbuffer: Templates [C++14] (P)

## Aufgaben

## Ringpuffer (6P)

Ein Ringpuffer ist eine Form der abstrakten Datenstruktur “Warteschlange” (Queue), die nur eine beschränkte Anzahl

von Elementen (Datensätzen) aufnehmen kann. Die Daten werden nach dem FIFO-Prinzip über die Funktion write() am Ende der Schlange eingefügt und mit der Funktion read() vom Anfang der Schlange entnommen.

Aus Effizienzgründen wird bei read() nur der Pointer auf das erste Element zurückgeliefert, das gelesene Element wird aber (noch) nicht aus dem Ringpuffer entfernt. Über ein Attribut head merkt man sich stattdessen, wo das nächste zu lesende Element liegt (auf dem Platz hinter dem aktuell gelesenen). Ist der Puffer voll, wird bei write() das älteste Element entfernt und das neue Element auf dem frei gewordenen Platz im internen Array elems eingefügt.

Der Ringpuffer soll Elemente vom Typ T (Template-Parameter) speichern. Es wird davon ausgegangen, dass die Pointer mit einem Allocator vom Typ alloc_t angelegt wurden; entsprechend werden die Elemente (Pointer) im Ringpuffer bei der Freigabe darüber auch wieder freigegeben.

Der Puffer kann effizient durch ein zur Laufzeit angelegtes Array mit size (Template-Parameter) Plätzen zur Speicherung der Pointer auf die Elemente realisiert werden. Die Ringstruktur wird durch Modulo-Operationen auf den Array-Indizes realisiert.

```cpp
/**
 * Template class to represent a ring buffer
 *
 * @param T is the type of elements to be stored (via pointer of type `T*`)
 * @param size is the max. number of elements that can be stored
 * @param alloc_t is the type of the allocator used to allocate the pointers to the elements (optional)
 */
template <typename T, size_t size, typename alloc_t = std::allocator<T>>
class RingBuffer {
public:
    /**
     * Constructor that creates a new ring buffer for max. `size` elements
     *
     * Initialises the attributes and allocates memory for `size` elements of type `T*` and let the
     * pointer `elems` point to this new array
     */
    RingBuffer();

    /**
     * Destructor
     *
     * 1. Frees all elements using an allocator of type `alloc_t`
     * 2. Frees the dynamically allocated array `elems`
     */
    ~RingBuffer();

    /**
     * Reading the first (oldest) element
     *
     * If an element has been read, the `head` points to the next element and `count` is decremented.
     * The read element is **not** released.
     *
     * @return Returns a pointer to the first (i.e. oldest) element of the buffer, but does not (yet)
     * delete it; returns `nullptr` if buffer is empty
     */
    T* readBuffer();

    /**
     * Adding a new element
     *
     * Appends the new element to the end of the queue. If the buffer is full, the oldest element will be
     * deleted with an allocator of type `alloc_t` and the pointer to the new element will be inserted in
     * this location.
     *
     * @param data is a pointer to the element to be added (allocated with an allocator of type `alloc_t`)
     */
    void writeBuffer(T *data);

    /**
     * Indicates the number of elements in the ring buffer relative to its size on the LED display
     */
    void displayStatus() const;

private:
    alloc_t m_allocator;    ///< allocator to free element pointers

    size_t count;           ///< number of elements currently stored in the buffer
    size_t head;            ///< points to the beginning of the buffer (oldest element)
    T **elems;              ///< array with `size` places of type `T*`, dynamically allocated
};
```

Implementieren Sie die Template-Klasse RingBuffer zu den Vorgaben (ringbuffer/RingBuffer.h).

### Allokatoren (4P)

Allokatoren kapseln Strategien für die Allokation und die Deallokation von Objekten. C++ stellt hierzu die Template-Klasse std::allocator_traits bereit, die analog zu einer abstrakten Klasse die recht umfangreichen Anforderungen an die Allokatoren(https://en.cppreference.com/w/cpp/named_req/Allocator) erfüllt. Die Container in der Standard-Bibliothek nutzen diese Template-Klasse zur Allokation und Deallokation von Elementen.

Die Methoden und Definitionen in std::allocator_traits stützen sich auf einigen wenigen in der Klasse des Template-Parameters implementierten Methoden und Definitionen ab. Inhaltlich sind die beiden Methoden allocate() und deallocate() wichtig, der Rest kann je nach Bedarf als Default implementiert werden.

```cpp
/**
 * Template class to represent a custom allocator, to be used via `std::allocator_traits`
 *
 * @param T is the type to be allocated/deallocated
 */
template <class T>
class CustomAllocator {
public:
    /**
     * Type trait to access type T
     */
    typedef T value_type;

    /**
     * Default constructor
     */
    CustomAllocator() {}

    /**
     * Copy constructor
     */
    template <class U> constexpr CustomAllocator (const CustomAllocator <U>&) noexcept {}

    /**
     * Allocates $n$ elements of type T and returns a pointer to the first element
     *
     * @param n is the number of elements to be allocated
     * @return pointer to the first element
     */
    T* allocate(size_t n);

    /**
     * Free's $n$ elements of type T that were allocated with this allocator using `allocate(n)`
     *
     * @param p is a pointer to the element (or to the first of several elements) to be free'd
     * @param n is the number of elements used in `allocate`
     */
    void deallocate(T* p, size_t n) noexcept;
};
/// Comparison of allocators
template <class T, class U>
bool operator==(const CustomAllocator <T>&, const CustomAllocator <U>&) { return true; }
template <class T, class U>
bool operator!=(const CustomAllocator <T>&, const CustomAllocator <U>&) { return false; }
```

Implementieren Sie drei verschiedene Allokatoren basierend auf der Template-Klasse CustomAllocator in den Vorgaben (ringbuffer/CustomAllocator.h):

1. Kapselung von malloc und free aus der C-Standardbibliothek
2. Kapselung der selbst implementierten Speicherverwaltung von Blatt 04
3. Einen No-Op-Allokator: Dieser wirft eine std::bad_alloc-Exception beim Versuch, allocate aufzurufen. Beim Aufruf von deallocate passiert nichts.

Bauen Sie ein Debugging ein, so dass man bei jedem Aufruf von allocate und deallocate über die Anzahl n sowie die allozierten/freigegebenen Speicherbereiche (Start- und End-Adressen) informiert wird.