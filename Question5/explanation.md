# Question 5 - Explanation

## Scenario

A system administrator is editing a configuration file using the `vi` editor. Before saving the file, the system crashes. Vim provides several recovery mechanisms to restore unsaved work.

---

## Recovery Mechanisms

### Swap File (.swp)

When a file is edited, Vim automatically creates a swap file (`.swp`). If the editor or system crashes, this file can be used to recover unsaved changes.

### Undo History

Vim maintains an undo history during the editing session. It allows recently made changes to be reversed. If persistent undo is enabled, the history can also be restored after reopening the file.

### Registers

Registers temporarily store copied, deleted, and yanked text. They help recover text during the editing session.

### Backup Files

Backup files store the previous version of a file before it is modified. They protect the original file in case of accidental changes.

### Auto-Recovery

When Vim detects an existing swap file after a crash, it displays a recovery option. Using the `:recover` command restores the unsaved changes from the swap file.

---

## Most Reliable Recovery Strategy

The most reliable recovery method is using the **swap file (.swp)** together with Vim's **auto-recovery** feature. This allows unsaved changes to be restored after an unexpected system crash, minimizing data loss.

---

## Conclusion

Vim provides several recovery mechanisms, including swap files, undo history, registers, backup files, and auto-recovery. Among these, swap file recovery is the most effective method for restoring unsaved work after a crash.