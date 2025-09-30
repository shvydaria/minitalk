# 📨 Minitalk

## 📌 Purpose
Minitalk demonstrates **Unix signal-based communication**.  
The client sends a string to the server by converting each character into bits.  
The server then reconstructs the message from those bits.  

![helpers](img/IMG_5668.jpeg)
---

## 🔗 Communication
Since only two signals are available, we map them as:  
- `SIGUSR1` → binary `1`  
- `SIGUSR2` → binary `0`  

This allows us to send any character **bit by bit**.  

---

## 🖥️ Server
- Sets up **signal handlers** to catch incoming bits.  
- Uses **static variables** to rebuild characters bit by bit.  
- Prints the reconstructed characters.  
- *(Bonus)* acknowledges the end of the message using `kill()`.  

---

## 💻 Client
- Takes each character and breaks it into bits.  
- Sends each bit as a signal using `send_char`.  
- The server replies with an acknowledgment.  
- The client prints a small confirmation message when receiving acknowledgment signals (`SIGUSR1`, `ack_hand`).  

---

## 📊 How it Works

+---------+ SIGUSR1 / SIGUSR2 +---------+

| Client | -----------------------------> | Server |

| |||||||||   |

| send | | rebuild |

| bits | | chars |

+---------+ +---------+

^ |
|  v

| acknowledgment (kill) |

+------------------------------------------+



[Understanding minitalk by Laura:](https://42-cursus.gitbook.io/guide/2-rank-02/minitalk/understand-minitalk)

![helpers](https://42-cursus.gitbook.io/guide/~gitbook/image?url=https%3A%2F%2F2977649544-files.gitbook.io%2F%7E%2Ffiles%2Fv0%2Fb%2Fgitbook-x-prod.appspot.com%2Fo%2Fspaces%252Fz2zo8aAL0o31034sj7J7%252Fuploads%252F5eY61q1QT9MHUx2Zxf7g%252Fminitalk_scheme.png%3Falt%3Dmedia%26token%3D22a960bd-d30e-4e73-a4e7-a683b9c4d931&width=768&dpr=2&quality=100&sign=af87f37b&sv=2)

