/**
 * @file RingBuffer.h
 * @brief Declaraciones para el buffer circular
 * @author Augusto Santini
 * @date 3/2020
 * @version 1.0
 */

#ifndef RINGBUFFER_H_
#define RINGBUFFER_H_

/** Estructura que define un buffer circular. Los elementos de esta estructura no deben ser modificados */
typedef struct
{
	const void *memory_buffer; //!< Puntero al buffer donde implementar el buffer circular
	const unsigned int data_size; //!< Tamaño en bytes de cada elemento a guardar en el buffer circular
	const unsigned int element_amount; //!< Cantidad de elementos a guardar en el buffer circular
	const unsigned int in_idx; //!< Indice de entrada
	const unsigned int out_idx; //!< Indice de salida
	const unsigned int current_elements_amount; //!< Cantidad de elementos actuales en el buffer circular
}RingBuffer;

/**
 * @brief Inicializar buffer circular
 * @param[in] rb Puntero al buffer circular a inicializar
 */
void RingBufferInit(RingBuffer *rb);

/**
 * @brief Obtener elemento de un buffer circular
 * @param[in] rb Puntero al buffer circular del cual obtener el elemento
 * @param[in] data Puntero a donde guardar el dato
 * @return En caso de no haber elementos disponibles, devuelve -1, en caso de exito devuelve 0
 */
int RingBufferPopElement(RingBuffer *rb, void *data);

/**
 * @brief Colocar elemento en un buffer circular
 * @param[in] rb Puntero al buffer circular en el cual colocar el elemento
 * @param[in] data Puntero al dato a colocar
 * @return En caso de no haber lugar disponible, devuelve -1, en caso de exito devuelve 0
 */
int RingBufferPutElement(RingBuffer *rb, const void *data);

/**
 * @brief Obtener cantidad de elementos actuales en el buffer circular
 * @param[in] rb Puntero al bufer circular a consultar
 * @return Cantidad de elementos que hay en el buffer circular
 */
unsigned int RingBufferGetAvailableElements(const RingBuffer *rb);

/**
 * @brief Obtener cantidad de lugares disponibles en el buffer circular
 * @param[in] rb Puntero al buffer circular a consultar
 * @return Cantidad de lugares libres en el buffer circular
 */
unsigned int RingBufferGetAvailableSpace(const RingBuffer *rb);

/**
 * @brief Limpiar buffer circular
 * @param[in] rb Puntero al buffer circular a limpiar
 */
void RingBufferClear(RingBuffer *rb);

#endif /* RINGBUFFER_H_ */
