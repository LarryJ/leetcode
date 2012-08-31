;;display the line number
(global-linum-mode t)
(setq linum-format "%d ")
;;set default directory
(setq default-directory "/home/larry/Desktop")
;;not display the startup
(setq inhibit-startup-message t)
;;display fit parenthese
(show-paren-mode t)
(setq show-paren-style 'parentheses)
;;no backup files
(setq make-backup-files nil)
(setq-default make-backup-files nil)
;;close auto save mode
(setq auto-save-mode nil)
(setq auto-save-default nil)
;;startup maximum
(defun my-maximized()
 (interactive)
 (x-send-client-message
  nil 0 nil "_NET_WM_STATE" 32
  '(1 "_NET_WM_STATE_MAXIMIZED_HORZ" 0))
 (interactive)
 (x-send-client-message
  nil 0 nil "_NET_WM_STATE" 32
  '(1 "_NET_WM_STATE_MAXIMIZED_VERT" 0)))
(my-maximized)
;;emacs template
(require 'template)
(template-initialize)
(put 'upcase-region 'disabled nil)
(put 'downcase-region 'disabled nil)

;;cedet
(load-file "/usr/share/emacs/cedet-1.0.1/common/cedet.el")
;;(global-ede-mode 1)
;;(semantic-load-enable-code-helpers)
;;(global-srecode-minor-mode 1)

;;semantic 
;;(semantic-load-enable-minimum-features)
(semantic-load-enable-code-helpers)
;;(semantic-load-enable-gaudy-code-helpers)
(semantic-load-enable-excessive-code-helpers)
;;(semantic-load-enable-semantic-debugging-helpers)

;;gcc setup
;;(require 'semantic-gcc)

;;smart complitions setup
;;(require 'semantic-ia)

;;short-cu
(global-set-key [f11] 'semantic-ia-fast-jump)
(global-set-key (kbd "M-n") 'semantic-ia-complete-symbol-menu)

;;tag-folding
(require 'semantic-tag-folding nil 'noerror)
(global-semantic-tag-folding-mode 1)

(global-set-key (kbd "C-c -") 'semantic-tag-folding-fold-block)
(global-set-key (kbd "C-c +") 'semantic-tag-folding-show-block)

(global-set-key (kbd "C-_") 'semantic-tag-folding-fold-all)
(global-set-key (kbd "C-+") 'semantic-tag-folding-show-all)
